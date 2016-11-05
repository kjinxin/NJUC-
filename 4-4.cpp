const
   oo = maxlongint div 2;

type
   art = record
     ben , fa : longint;
   end;

var
   e : array[ 0 .. 1000000 ] of art;{用最新的数组实现连表，存边}
   ans , m , len , n , t , i , x , y , j , k , top , kind : longint;
   enter , s , last , low , list , dfs , cost , mincost : array[ 0 .. 10000 ] of longint;

function min( x , y : longint ) : longint;
   begin
     if x < y then exit( x ) else exit( y );
   end;

function ok( y : longint ) : boolean;{是否出现在栈中，如果出现，表示是在这个节点之前已经被遍历过}
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
     low[ x ] := top;{high值}
     y := last[ x ];
     while y > 0 do
       begin

         if dfs[ e[ y ].ben ] = 0{两种情况，是否已经被遍历过}
           then begin
             slove( e[ y ].ben );
             if low[ e[ y ].ben ] < low[ x ]
               then low[ x ] := low[ e[ y ].ben ];
                end
           else if ok( e[ y ].ben ){是否是和这个节点在同一个支链上}
                  then
              if dfs[ e[ y ].ben ] < low[ x ] then
              low[ x ] := low[ e[ y ].ben ];
       y := e[ y ].fa;
     end;

     if low[ x ] = dfs[ x ] then begin{如果，这个节点的high值就是它本身，表示这个节点及它的子树是一个强连通分支}
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

procedure make_edge( x , y : longint );{用数组做连表}
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

   fillchar( dfs , sizeof( dfs ) , 0 )；{分解图，就强连通分支}
   for i := 1 to n do
     if dfs[ i ] = 0 then begin
       top := 0;
       slove( i );
     end;

   for i := 1 to kind do mincost[ i ] := maxlongint;{一个强连通分支中的min(cost[ i ] , 0<i<=n )为这个强连通分支的cost值}
   for i := 1 to n do
     mincost[ s[ i ] ] := min( mincost[ s[ i ] ] , cost[ i ] );

   for i := 1 to n do begin{缩图}
     x := last[ i ];
     while x <> 0 do begin
       if s[ i ] <> s[ e[ x ].ben ] then
         inc( enter[ s[ e[ x ].ben ] ] );
       x := e[ x ].fa;
     end;
   end;
   { 拓扑 }
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
