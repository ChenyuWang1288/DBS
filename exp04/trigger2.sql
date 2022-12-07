Delimiter $$
CREATE TRIGGER trg_tb_sc_insert1 before INSERT
   ON SC
   for each row
   begin
   declare msg varchar(100);
	if new.cid not in (select cid from c)
    then
		set msg = ("课程号不存在！");
        signal sqlstate 'HY000' set message_text = msg;
	end if;
    end; $$

