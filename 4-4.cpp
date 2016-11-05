const
   oo = maxlongint div 2;

type
   art = record
     ben , fa : longint;
   end;

var
   e : array[ 0 .. 1000000 ] of art;{�����µ�����ʵ���������}
   ans , m , len , n , t , i , x , y , j , k , top , kind : longint;
   enter , s , last , low , list , dfs , cost , mincost : array[ 0 .. 10000 ] of longint;

function min( x , y : longint ) : longint;
   begin
     if x < y then exit( x ) else exit( y );
   end;

function ok( y : longint ) : boolean;{�Ƿ������ջ�У�������֣���ʾ��������ڵ�֮ǰ�Ѿ���������}
   var
     i : longint;
   begin
     for i := 1 to top do
       if list[ i ] = y then exit( true );
     exit( false );
   end;

procedure slove( x : longint );
   var
     i , j , y : longint;
   begin
     inc( top );
     list[ top ] := x;
     dfs[ x ] := top;
     low[ x ] := top;{highֵ}
     y := last[ x ];
     while y > 0 do
       begin

         if dfs[ e[ y ].ben ] = 0{����������Ƿ��Ѿ���������}
           then begin
             slove( e[ y ].ben );
             if low[ e[ y ].ben ] < low[ x ]
               then low[ x ] := low[ e[ y ].ben ];
                end
           else if ok( e[ y ].ben ){�Ƿ��Ǻ�����ڵ���ͬһ��֧����}
                  then
              if dfs[ e[ y ].ben ] < low[ x ] then
              low[ x ] := low[ e[ y ].ben ];
       y := e[ y ].fa;
     end;

     if low[ x ] = dfs[ x ] then begin{���������ڵ��highֵ������������ʾ����ڵ㼰����������һ��ǿ��ͨ��֧}
       inc( kind );
       repeat
         s[ list[ top ] ] := kind;
         dec( top );
       until list[ top + 1 ] = x;
     end;
   end;

function find: longint;
   var
     best , i , j : longint;
   begin
     best := oo;
     for i := 1 to kind do
       if ( enter[ i ] = 0 ) and ( mincost[ i ] = oo ) then
     for j := 1 to n do
       if s[ j ] = i then best := min( j , best );
     writeln( best );
   end;

procedure make_edge( x , y : longint );{������������}
   begin
     inc( len );
     e[ len ].ben := y;
     e[ len ].fa := last[ x ];
     last[ x ] := len;
   end;

begin
   assign( input , 'age.in' );
   reset( input );
   assign( output , 'age.out' );
   rewrite( output );

   readln( n , t );
   for i := 1 to n do cost[ i ] := oo;
   for i := 1 to t do begin
     readln( x , y );
     cost[ x ] := y;
   end;
   readln( m );
   for i := 1 to m do begin
     readln( x , y );
     make_edge( x , y );
   end;

   fillchar( dfs , sizeof( dfs ) , 0 )��{�ֽ�ͼ����ǿ��ͨ��֧}
   for i := 1 to n do
     if dfs[ i ] = 0 then begin
       top := 0;
       slove( i );
     end;

   for i := 1 to kind do mincost[ i ] := maxlongint;{һ��ǿ��ͨ��֧�е�min(cost[ i ] , 0<i<=n )Ϊ���ǿ��ͨ��֧��costֵ}
   for i := 1 to n do
     mincost[ s[ i ] ] := min( mincost[ s[ i ] ] , cost[ i ] );

   for i := 1 to n do begin{��ͼ}
     x := last[ i ];
     while x <> 0 do begin
       if s[ i ] <> s[ e[ x ].ben ] then
         inc( enter[ s[ e[ x ].ben ] ] );
       x := e[ x ].fa;
     end;
   end;
   { ���� }
   for i := 1 to kind do
     if ( enter[ i ] = 0 ) and ( mincost[ i ] = oo ) then begin
       writeln( 'NO' );
       writeln( find );
       close( output );
       halt;
     end;

   writeln( 'YES' );
   ans := 0;
   for i := 1 to kind do
     if enter[ i ] = 0 then inc( ans , mincost[ i ] );
   writeln( ans );
   close( output );
end.
