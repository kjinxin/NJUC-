1./**
2. * Android��Ƶ����
3. * 1����ʼ��SDK 2�����ӷ������� 3���û���¼��4�����뷿�䣻5���򿪱�����Ƶ��6������Է���Ƶ
4. */
5.public class VideoChatActivity extends Activity implements AnyChatBaseEvent
6.{
7.    private AnyChatCoreSDK anychat;         // ����SDK
8.    private SurfaceView remoteSurfaceView;  // �Է���Ƶ
9.    private SurfaceView localSurfaceView;   // ������Ƶ
10.    private ConfigEntity configEntity;
11.    private boolean bSelfVideoOpened = false;   // ������Ƶ�Ƿ��Ѵ�
12.    private boolean bOtherVideoOpened = false;  // �Է���Ƶ�Ƿ��Ѵ�
13.    private TimerTask mTimerTask;               // ��ʱ��
14.    private Timer mTimer = new Timer(true);
15.    private Handler handler;                    // ��Handler�������ˢ�¼�ʱ��Ƶ
16.    private List<String> userlist = new ArrayList<String>();//���������û��б�
17.    private int userid;                         // �û�ID
18.    @Override
19.    public void onCreate(Bundle savedInstanceState)
20.    {
21.        super.onCreate(savedInstanceState);
22.        setContentView(R.layout.activity_video_chat);
23.        remoteSurfaceView = (SurfaceView) findViewById(R.id.surface_remote);
24.        localSurfaceView = (SurfaceView) findViewById(R.id.surface_local);
25.        configEntity = ConfigService.LoadConfig(this);//������Ƶͨ������
26.        loginSystem();// ��ʼ��SDK ���ӷ�����
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
37.                VideoChat();// �������ʾ��ʱ��Ƶͨ������
38.                super.handleMessage(msg);
39.            }
40.        };
41.    }
42.    // ��ʼ��SDK ���ӷ�����
43.    private void loginSystem(){
44.        if (anychat == null){
45.            anychat = new AnyChatCoreSDK();
46.            anychat.SetBaseEvent(this);         // ���û����¼��ص�����
47.            if (configEntity.useARMv6Lib != 0)  // ʹ��ARMv6ָ�
48.                anychat.SetSDKOptionInt(AnyChatDefine.
49.                        BRAC_SO_CORESDK_USEARMV6LIB, 1);
50.            anychat.InitSDK(android.os.Build.VERSION.SDK_INT, 0); // ��ʼ��SDK
51.        }
52.        anychat.Connect("demo.anychat.cn", 8906);// ���ӷ�����
53.    }
54.    // ��ʾ��ʱ��Ƶͨ������
55.    public void VideoChat(){
56.        if (!bOtherVideoOpened){
57.            if (anychat.GetCameraState(userid) == 2
58.                    && anychat.GetUserVideoWidth(userid) != 0){
59.                SurfaceHolder holder = remoteSurfaceView.getHolder();
60.                holder.setFormat(PixelFormat.RGB_565);
61.                holder.setFixedSize(anychat.GetUserVideoWidth(userid),
62.                        anychat.GetUserVideoHeight(userid));
63.                Surface s = holder.getSurface();            // �����Ƶ����
64.                anychat.SetVideoPos(userid, s, 0, 0, 0, 0); // ����API��ʾ��Ƶ����
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
83.            Toast.makeText(VideoChatActivity.this, "���ӷ�����ʧ�ܣ��Զ����������Ժ�...", Toast.LENGTH_SHORT).show();
84.        }
85.        anychat.Login("android", "");               // ���������ӳɹ� �û���¼
86.    }
87.    public void OnAnyChatLoginMessage(int dwUserId, int dwErrorCode){
88.        if (dwErrorCode == 0) {
89.            Toast.makeText(this, "��¼�ɹ���", Toast.LENGTH_SHORT).show();
90.            anychat.EnterRoom(1, "");               // �û���¼�ɹ� ���뷿��
91.            ApplyVideoConfig();
92.        } else {
93.            Toast.makeText(this, "��¼ʧ�ܣ�������룺" + dwErrorCode, Toast.LENGTH_SHORT).show();
94.        }
95.    }
96.    public void OnAnyChatEnterRoomMessage(int dwRoomId, int dwErrorCode){
97.        if (dwErrorCode == 0) {                     // ���뷿��ɹ�  �򿪱�������Ƶ
98.            Toast.makeText(this, "���뷿��ɹ�", Toast.LENGTH_SHORT).show();
99.            anychat.UserCameraControl(-1, 1);       // �򿪱�����Ƶ
100.            anychat.UserSpeakControl(-1, 1);        // �򿪱�����Ƶ
101.        } else {
102.            Toast.makeText(this, "���뷿��ʧ�ܣ�������룺" + dwErrorCode, Toast.LENGTH_SHORT).show();
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
114.                anychat.UserCameraControl(userid, 1);// �����û���Ƶ
115.                anychat.UserSpeakControl(userid, 1); // �����û���Ƶ
116.            }
117.            else {
118.                Toast.makeText(VideoChatActivity.this, "��ǰû�������û�", Toast.LENGTH_SHORT).show();
119.            }
120.        }
121.    }
122.    public void OnAnyChatUserAtRoomMessage(int dwUserId, boolean bEnter){
123.        if (bEnter) {//���û����뷿��
124.            userlist.add(dwUserId+"");
125.        }
126.        else {       //�û��뿪����
127.            if (dwUserId == userid)
128.            {
129.                Toast.makeText(VideoChatActivity.this, "��Ƶ�û�������", Toast.LENGTH_SHORT).show();
130.                anychat.UserCameraControl(userid, 0);// �ر��û���Ƶ
131.                anychat.UserSpeakControl(userid, 0); // �ر��û���Ƶ
132.                userlist.remove(userid+"");          //�Ƴ����û�
133.                if (userlist.size() != 0)
134.                {
135.                    String temp =userlist.get(0);
136.                    userid = Integer.parseInt(temp);
137.                    anychat.UserCameraControl(userid, 1);// ���������û���Ƶ
138.                    anychat.UserSpeakControl(userid, 1); // ���������û���Ƶ
139.                }
140.            }
141.            else {
142.                userlist.remove(dwUserId+"");    //�Ƴ����û�
143.            }
144.        }
145.    }
146.    public void OnAnyChatLinkCloseMessage(int dwErrorCode){
147.        Toast.makeText(VideoChatActivity.this, "���ӹرգ�error��" + dwErrorCode, Toast.LENGTH_SHORT).show();
148.    }
149.    @Override
150.    protected void onDestroy(){ //�����˳�
151.        anychat.LeaveRoom(-1);  //�뿪����
152.        anychat.Logout();       //ע����¼
153.        anychat.Release();      //�ͷ���Դ
154.        mTimer.cancel();
155.        super.onDestroy();
156.    }
157.    // ���������ļ�������Ƶ����
158.    private void ApplyVideoConfig(){
159.        if (configEntity.configMode == 1) // �Զ�����Ƶ��������
160.        {
161.            // ���ñ�����Ƶ��������ʣ��������Ϊ0�����ʾʹ����������ģʽ��
162.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_BITRATECTRL,configEntity.videoBitrate);
163.            if (configEntity.videoBitrate == 0)
164.            {
165.                // ���ñ�����Ƶ���������
166.                anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_QUALITYCTRL,configEntity.videoQuality);
167.            }
168.            // ���ñ�����Ƶ�����֡��
169.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_FPSCTRL,configEntity.videoFps);
170.            // ���ñ�����Ƶ����Ĺؼ�֡���
171.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_GOPCTRL,configEntity.videoFps * 4);
172.            // ���ñ�����Ƶ�ɼ��ֱ���
173.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_WIDTHCTRL,configEntity.resolution_width);
174.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_HEIGHTCTRL,configEntity.resolution_height);
175.            // ������Ƶ����Ԥ�������ֵԽ�󣬱�������Խ�ߣ�ռ��CPU��ԴҲ��Խ�ߣ�
176.            anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_PRESETCTRL,configEntity.videoPreset);
177.        }
178.        // ����Ƶ������Ч
179.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_APPLYPARAM,configEntity.configMode);
180.        // P2P����
181.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_NETWORK_P2PPOLITIC,configEntity.enableP2P);
182.        // ������ƵOverlayģʽ����
183.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_OVERLAY,configEntity.videoOverlay);
184.        // ������������
185.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_AUDIO_ECHOCTRL,configEntity.enableAEC);
186.        // ƽ̨Ӳ����������
187.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_CORESDK_USEHWCODEC,configEntity.useHWCodec);
188.        // ��Ƶ��תģʽ����
189.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_ROTATECTRL,configEntity.videorotatemode);
190.        // ��Ƶƽ������ģʽ����
191.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_STREAM_SMOOTHPLAYMODE,configEntity.smoothPlayMode);
192.        // ��Ƶ�ɼ���������
193.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_CAPDRIVER,configEntity.videoCapDriver);
194.        // ������Ƶ�ɼ�ƫɫ��������
195.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_LOCALVIDEO_FIXCOLORDEVIA,configEntity.fixcolordeviation);
196.        // ��Ƶ��ʾ��������
197.        anychat.SetSDKOptionInt(AnyChatDefine.BRAC_SO_VIDEOSHOW_DRIVERCTRL,configEntity.videoShowDriver);
198.    }
199.}
