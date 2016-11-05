1./**
2. * Android视频聊天
3. * 1、初始化SDK 2、连接服务器、 3、用户登录；4、进入房间；5、打开本地视频；6、请求对方视频
4. */
5.public class VideoChatActivity extends Activity implements AnyChatBaseEvent
6.{
7.    private AnyChatCoreSDK anychat;         // 核心SDK
8.    private SurfaceView remoteSurfaceView;  // 对方视频
9.    private SurfaceView localSurfaceView;   // 本地视频
10.    private ConfigEntity configEntity;
11.    private boolean bSelfVideoOpened = false;   // 本地视频是否已打开
12.    private boolean bOtherVideoOpened = false;  // 对方视频是否已打开
13.    private TimerTask mTimerTask;               // 定时器
14.    private Timer mTimer = new Timer(true);
15.    private Handler handler;                    // 用Handler来不间断刷新即时视频
16.    private List<String> userlist = new ArrayList<String>();//保存在线用户列表
17.    private int userid;                         // 用户ID
18.    @Override
19.    public void onCreate(Bundle savedInstanceState)
20.    {
21.        super.onCreate(savedInstanceState);
22.        setContentView(R.layout.activity_video_chat);
23.        remoteSurfaceView = (SurfaceView) findViewById(R.id.surface_remote);
24.        localSurfaceView = (SurfaceView) findViewById(R.id.surface_local);
25.        configEntity = ConfigService.LoadConfig(this);//加载视频通话设置
26.        loginSystem();// 初始化SDK 连接服务器
27.        mTimerTask = new TimerTask(){
28.            public void run(){
29.                Message mesasge = new Message();
30.                handler.sendMessage(mesasge);
31.            }
32.        };
33.        mTimer.schedule(mTimerTask, 1000, 100);
34.        handler = new Handler(){
35.            @Override
36.            public void handleMessage(Message msg){
37.                VideoChat();// 不间断显示即时视频通话画面
38.                super.handleMessage(msg);
39.            }
40.        };
41.    }
42.    // 初始化SDK 连接服务器
43.    private void loginSystem(){
44.        if (anychat == null){
45.            anychat = new AnyChatCoreSDK();
46.            anychat.SetBaseEvent(this);         // 设置基本事件回调函数
47.            if (configEntity.useARMv6Lib != 0)  // 使用ARMv6指令集
48.                anychat.SetSDKOptionInt(AnyChatDefine.
49.                        BRAC_SO_CORESDK_USEARMV6LIB, 1);
50.            anychat.InitSDK(android.os.Build.VERSION.SDK_INT, 0); // 初始化SDK
51.        }
52.        anychat.Connect("demo.anychat.cn", 8906);// 连接服务器
53.    }
54.    // 显示即时视频通话画面
55.    public void VideoChat(){
56.        if (!bOtherVideoOpened){
57.            if (anychat.GetCameraState(userid) == 2
58.                    && anychat.GetUserVideoWidth(userid) != 0){
59.                SurfaceHolder holder = remoteSurfaceView.getHolder();
60.                holder.setFormat(PixelFormat.RGB_565);
61.                holder.setFixedSize(anychat.GetUserVideoWidth(userid),
62.                        anychat.GetUserVideoHeight(userid));
63.                Surface s = holder.getSurface();            // 获得视频画面
64.                anychat.SetVideoPos(userid, s, 0, 0, 0, 0); // 调用API显示视频画面
65.                bOtherVideoOpened = true;
66.            }
67.        }
68.        if (!bSelfVideoOpened){
69.            if (anychat.GetCameraState(-1) == 2
70.                    && anychat.GetUserVideoWidth(-1) != 0){
71.                SurfaceHolder holder = localSurfaceView.getHolder();
72.                holder.setFormat(PixelFormat.RGB_565);
73.                holder.setFixedSize(anychat.GetUserVideoWidth(-1),
74.                        anychat.GetUserVideoHeight(-1));
75.                Surface s = holder.getSurface();
76.                anychat.SetVideoPos(-1, s, 0, 0, 0, 0);
77.                bSelfVideoOpened = true;
78.            }
79.        }
80.    }
81.    public void OnAnyChatConnectMessage(boolean bSuccess){
82.        if (!bSuccess){
83.            Toast.makeText(VideoChatActivity.this, "连接服务器失败，自动重连，请稍后...", Toast.LENGTH_SHORT).show();
84.        }
85.        anychat.Login("android", "");               // 服务器连接成功 用户登录
86.    }
87.    public void OnAnyChatLoginMessage(int dwUserId, int dwErrorCode){
88.        if (dwErrorCode == 0) {
89.            Toast.makeText(this, "登录成功！", Toast.LENGTH_SHORT).show();
90.            anychat.EnterRoom(1, "");               // 用户登录成功 进入房间
91.            ApplyVideoConfig();
92.        } else {
93.            Toast.makeText(this, "登录失败，错误代码：" + dwErrorCode, Toast.LENGTH_SHORT).show();
94.        }
95.    }
96.    public void OnAnyChatEnterRoomMessage(int dwRoomId, int dwErrorCode){
97.        if (dwErrorCode == 0) {                     // 进入房间成功  打开本地音视频
98.            Toast.makeText(this, "进入房间成功", Toast.LENGTH_SHORT).show();
99.            anychat.UserCameraControl(-1, 1);       // 打开本地视频
100.            anychat.UserSpeakControl(-1, 1);        // 打开本地音频
101.        } else {
102.            Toast.makeText(this, "进入房间失败，错误代码：" + dwErrorCode, Toast.LENGTH_SHORT).show();
103.        }
104.    }
105.    public void OnAnyChatOnlineUserMessage(int dwUserNum, int dwRoomId){
106.        if (dwRoomId == 1){
107.            int user[] = anychat.GetOnlineUser();
108.            if (user.length != 0){
109.                for (int i = 0; i < user.length; i++){
110.                    userlist.add(user[i]+"");
111.                }
112.                String temp =userlist.get(0);
113.                userid = Integer.parseInt(temp);
114.                anychat.UserCameraControl(userid, 1);// 请求用户视频
115.                anychat.UserSpeakControl(userid, 1); // 请求用户音频
116.            }
117.            else {
118.                Toast.makeText(VideoChatActivity.this, "当前没有在线用户", Toast.LENGTH_SHORT).show();
119.            }
120.        }
121.    }
122.    public void OnAnyChatUserAtRoomMessage(int dwUserId, boolean bEnter){
123.        if (bEnter) {//新用户进入房间
124.            userlist.add(dwUserId+"");
125.        }
126.        else {       //用户离开房间
127.            if (dwUserId == userid)
128.            {
129.                Toast.makeText(VideoChatActivity.this, "视频用户已下线", Toast.LENGTH_SHORT).show();
130.                anychat.UserCameraControl(userid, 0);// 关闭用户视频
131.                anychat.UserSpeakControl(userid, 0); // 关闭用户音频
132.                userlist.remove(userid+"");          //移除该用户
133.                if (userlist.size() != 0)
134.                {
135.                    String temp =userlist.get(0);
136.                    userid = Integer.parseInt(temp);
137.                    anychat.UserCameraControl(userid, 1);// 请求其他用户视频
138.                    anychat.UserSpeakControl(userid, 1); // 请求其他用户音频
139.                }
140.            }
141.            else {
142.                userlist.remove(dwUserId+"");    //移除该用户
143.            }
144.        }
145.    }
146.    public void OnAnyChatLinkCloseMessage(int dwErrorCode){
147.        Toast.makeText(VideoChatActivity.this, "连接关闭，error：" + dwErrorCode, Toast.LENGTH_SHORT).show();
148.    }
149.    @Override
150.    protected void onDestroy(){ //程序退出
151.        anychat.LeaveRoom(-1);  //离开房间
152.        anychat.Logout();       //注销登录
153.        anychat.Release();      //释放资源
154.        mTimer.cancel();
155.        super.onDestroy();
156.    }
157.    // 根据配置文件配置视频参数
158.    private void ApplyVideoConfig(){
159.        if (configEntity.configMode == 1) // 自定义视频参数配置
160.        {
161.            // 设置本地视频编码的码率（如果码率为0，则表示使用质量优先模式）
162.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_BITRATECTRL,configEntity.videoBitrate);
163.            if (configEntity.videoBitrate == 0)
164.            {
165.                // 设置本地视频编码的质量
166.                anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_QUALITYCTRL,configEntity.videoQuality);
167.            }
168.            // 设置本地视频编码的帧率
169.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_FPSCTRL,configEntity.videoFps);
170.            // 设置本地视频编码的关键帧间隔
171.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_GOPCTRL,configEntity.videoFps * 4);
172.            // 设置本地视频采集分辨率
173.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_WIDTHCTRL,configEntity.resolution_width);
174.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_HEIGHTCTRL,configEntity.resolution_height);
175.            // 设置视频编码预设参数（值越大，编码质量越高，占用CPU资源也会越高）
176.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_PRESETCTRL,configEntity.videoPreset);
177.        }
178.        // 让视频参数生效
179.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_APPLYPARAM,configEntity.configMode);
180.        // P2P设置
181.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_NETWORK_P2PPOLITIC,configEntity.enableP2P);
182.        // 本地视频Overlay模式设置
183.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_OVERLAY,configEntity.videoOverlay);
184.        // 回音消除设置
185.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_AUDIO_ECHOCTRL,configEntity.enableAEC);
186.        // 平台硬件编码设置
187.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_CORESDK_USEHWCODEC,configEntity.useHWCodec);
188.        // 视频旋转模式设置
189.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_ROTATECTRL,configEntity.videorotatemode);
190.        // 视频平滑播放模式设置
191.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_STREAM_SMOOTHPLAYMODE,configEntity.smoothPlayMode);
192.        // 视频采集驱动设置
193.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_CAPDRIVER,configEntity.videoCapDriver);
194.        // 本地视频采集偏色修正设置
195.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_FIXCOLORDEVIA,configEntity.fixcolordeviation);
196.        // 视频显示驱动设置
197.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_VIDEOSHOW_DRIVERCTRL,configEntity.videoShowDriver);
198.    }
199.}
