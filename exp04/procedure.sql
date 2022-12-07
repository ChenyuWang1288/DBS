use university;
delimiter //
create procedure total_credit(in stu_id varchar(20), out credit_count integer)
	begin
		select count(*) into credit_count
        from SC
        where SC.SID = stu_id;
	end; //
delimiter ;