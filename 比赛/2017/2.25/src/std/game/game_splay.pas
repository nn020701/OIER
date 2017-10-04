type
  splaya=record
    l,r,key,size,p,min,max:int64;
    end;
var
  a:array[0..1000005]of splaya;
  a1,max1,max2,min1,min2,can1,can2:array[0..1000005]of int64;
  root,n,j,q,x,y,z,ll,s1,ans:int64;
  i:longint;
  ch:char;


  procedure out(y,x:int64);
    begin
    if x=0 then exit;
    out(x,a[x].l);
    writeln(y,' ',x,' ',a[x].key,' ',a[x].max,' ',a[a[x].r].max);
    //writeln(a[x].key,' 'a[x].min);
    out(x,a[x].r);
    end;


  procedure update1(x,z:int64);   //节点x加z
    begin
      a[x].key:=a[x].key+z;
      a[x].min:=a[x].min+z;
      a[x].max:=a[x].max+z;
    end;

  procedure update(x:int64);   //每次旋转完更新节点的两个域
    begin
    a[x].size:=a[a[x].l].size+a[a[x].r].size+1;
    a[x].min:=a[x].key;
    if a[a[x].l].min<a[x].min then a[x].min:=a[a[x].l].min;
    if a[a[x].r].min<a[x].min then a[x].min:=a[a[x].r].min;

    a[x].max:=a[x].key;
    if a[a[x].l].max>a[x].max then a[x].max:=a[a[x].l].max;
    if a[a[x].r].max>a[x].max then a[x].max:=a[a[x].r].max;

    end;




procedure rightrotate(x:int64);   //右旋
var
	y,z:int64;
begin
	y:=a[x].p;
	z:=a[y].p;
	if a[z].l=y then a[z].l:=x
		else a[z].r:=x;
	a[x].p:=z;
	a[y].p:=x;
	a[y].l:=a[x].r;
	a[x].r:=y;
	a[a[y].l].p:=y;
	update(y);
end;

procedure leftrotate(x:int64);   //左旋
var
	y,z:int64;
begin
	y:=a[x].p;
	z:=a[y].p;
	if a[z].l=y then a[z].l:=x
		else a[z].r:=x;
	a[x].p:=z;
	a[y].p:=x;
	a[y].r:=a[x].l;
	a[x].l:=y;
	a[a[y].r].p:=y;
	update(y);
end;

procedure splay(var root:int64;x:int64);  //核心操作:单旋splay
var
  tmp:int64;
  begin
  if x=0 then exit;
  tmp:=a[root].p;
	while a[x].p<>tmp do
		if a[a[x].p].l=x then rightrotate(x)
			else leftrotate(x);
  update(x);
  root:=x;
  end;


function fsmall(t,x:int64):int64;   //找值小于x的最大节点
begin
        fsmall:=0;
        while t<>0 do
        begin
        //writeln(t,'$');
        if (a[a[t].r].max>x)then begin
          t:=a[t].r;
          continue;
          end;

        if (a[a[t].r].max<=x)and(a[t].key>x)then begin
          break;
          end;
        t:=a[t].l;
        end;
        fsmall:=t;
        splay(root,fsmall);
end;


  function big(x,y:int64):boolean;
    begin
    if x>=y then big:=true
      else big:=false;
    end;


  procedure insert(var root:int64;z:int64);//插入
  var
    x,y:int64;
    begin
    y:=0;
    x:=root;
    while x<>0 do
      begin
      y:=x;
      if big(x,z) then x:=a[x].l
        else x:=a[x].r;
      end;
    a[z].p:=y;
    if y=0 then root:=z
      else if big(y,z) then a[y].l:=z
        else a[y].r:=z;
    splay(root,z);
    end;


  begin
  assign(input,'game.in'); reset(input);
  assign(output,'game.out'); rewrite(output);
  readln(n);
  for i:=1 to n do read(a1[i]);
  root:=0;
  a[0].max:=-100000000000;
  a[0].min:=100000000000;
  a[0].key:=-100000000000;
  a[1].key:=100000000000;
  insert(root,1);
  for i:=1 to n do
    begin
    a[i+1].key:=a1[i];
    insert(root,i+1);
    j:=fsmall(root,a1[i]);
    //out(0,root);
    if root+1=i+1 then begin
      can1[i]:=1;
      end
      else begin
      splay(a[root].r,i+1);
      min1[i]:=a[a[a[root].r].l].min;
      max1[i]:=a[a[a[root].r].l].max;
      end;
    //writeln('*',j,' ',min1[i],' ',max1[i]);
    end;

  fillchar(a,sizeof(a),0);
  root:=0;
  a[0].max:=-100000000000;
  a[0].min:=10000000000;
  a[0].key:=-100000000000;
  a[1].key:=100000000000;
  insert(root,1);
  for i:=1 to n do
    begin
    a[i+1].key:=a1[n-i+1];
    insert(root,i+1);
    j:=fsmall(root,a1[n-i+1]);
    if root+1=i+1 then begin
      can2[n-i+1]:=1;
      end
      else begin
      splay(a[root].r,i+1);
      min2[n-i+1]:=a[a[a[root].r].l].min;
      max2[n-i+1]:=a[a[a[root].r].l].max;
      end;
    //writeln('*',j,' ',min2[i],' ',max2[i]);
    end;
  for i:=1 to n do
    begin
    ans:=-10000000000;
    if (can1[i]=1)or(can2[i]=1) then begin
      writeln('-1');
      continue;
      end;

    if max1[i]-min2[i]>ans then ans:=max1[i]-min2[i];
    if max2[i]-min1[i]>ans then ans:=max2[i]-min1[i];
    writeln(ans);
    end;

  close(input); close(output);
  end.




