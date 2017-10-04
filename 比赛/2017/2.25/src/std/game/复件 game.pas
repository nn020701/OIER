var
  n,i,j:longint;
  ans:int64;
  a,f,f1,min,min1,max,max1:array[0..1000005]of int64;
  begin
  assign(input,'game.in'); reset(input);
  assign(output,'game.out'); rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  a[0]:=maxlongint;
  a[n+1]:=maxlongint;
  for i:=1 to n do
    begin
    min[i]:=maxlongint;
    max[i]:=-maxlongint;
    j:=i-1;
    while a[j]<=a[i] do 
      begin
      if a[j]<min[i] then min[i]:=a[j];
      if a[j]>max[i] then max[i]:=a[j];
      if min[j]<min[i] then min[i]:=min[j];
      if max[j]>max[i] then max[i]:=max[j];
      j:=f[j]-1;
      end;
    f[i]:=j+1;
    //writeln(f[i]);
    end;
  f1:=f;
  min1:=min;
  max1:=max;
  
  
  for i:=n downto 1 do
    begin
    min[i]:=maxlongint;
    max[i]:=-maxlongint;
    j:=i+1;
    while a[j]<=a[i] do 
      begin
      if a[j]<min[i] then min[i]:=a[j];
      if a[j]>max[i] then max[i]:=a[j];
      if min[j]<min[i] then min[i]:=min[j];
      if max[j]>max[i] then max[i]:=max[j];
      j:=f[j]+1;
      end;
    f[i]:=j-1;
    end;
    
  for i:=1 to n do
    begin
    ans:=-maxlongint;
  if (f1[i]=i)or(f[i]=i) then writeln(-1)
      else begin
    if max1[i]-min[i]>ans then ans:=max1[i]-min[i];
    if max[i]-min1[i]>ans then ans:=max[i]-min1[i];
    writeln(ans);
    end;
    end;
  close(output);
  end.