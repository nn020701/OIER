var
    a:array[1..20]of char;
	data:array[1..20]of integer;
	n,i,h,ans,len:integer;
procedure merge;
begin
	data[h-1]:=data[h-1]+data[h];
	dec(h);
	ans:=ans+1;
end;
begin
	assign(input,'fast.in');
	assign(output,'fast.out');
	reset(input);
	rewrite(output);
	readln(len);
    for i:=1 to len do
        read(a[i]);
    for i:=1 to len do
        n:=n*2+ord(a[i])-ord('0');
	h:=1;
	data[h]:=1;
	ans:=0;
	for i:=2 to n do
	begin
		inc(h);
		data[h]:=1;
		while (h>1)and(data[h]=data[h-1]) do
		merge;
	end;
	writeln(ans);
	close(input);
	close(output);
end.
