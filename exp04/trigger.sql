Delimiter $$
create trigger s_delete_check after delete on S
for each row
begin
	delete from SC where SC.SID = old.SID;
end;
