const
  wei=25;
  var
  i,j,n,t,x,y,x1,y1,sum,len,k,xx1,yy1:longint;
  a:array[1..250,1..250]of longint;
  son:array[1..250,1..35]of longint;
  begin
  assign(input,'stock.in'); reset(input);
  assign(output,'stock.out'); rewrite(output);
  //writeln('*');
  readln(n,t);
  len:=n div wei;
  if n mod wei<>0 then inc(len);

  for i:=1 to n do
    begin
    x1:=i div wei+1;y1:=i mod wei;
    if y1=0 then y1:=wei;
    if i mod wei=0 then dec(x1);
    dec(y1);
    son[i,x1]:=son[i,x1]or (1 shl y1);
    end;


  for i:=1 to t do
    begin
    readln(x,y);
    if a[x,y]=1 then begin
      continue;
      end;

    x1:=x div wei+1;y1:=x mod wei;
    if y1=0 then y1:=wei;
    if x mod wei=0 then dec(x1);
    dec(y1);
    if son[y,x1]and(1 shl y1)=0 then begin
      a[x,y]:=1;
	xx1:=x1;yy1:=y1;
      for j:=1 to n do
        if son[j,xx1]and(1 shl yy1)>0 then begin
	
	x1:=y div wei+1;y1:=y mod wei;
    	if y1=0 then y1:=wei;
    	if y mod wei=0 then dec(x1);
    	dec(y1);
	if son[j][x1]and(1 shl y1)=1 then begin
                //writeln('RP');
                continue;
                end;

        for k:=1 to len do son[j,k]:=son[j,k]or son[y,k];
        end;
      end
      else inc(sum);
    end;

  writeln(sum);
  close(input);
  close(output);
  end.


