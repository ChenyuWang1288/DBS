use university;
delimiter //
create function `course_num`(id varchar(20))
	returns int
    begin
    declare c_count int;
		select count(*) into c_count
        from SC
        where SID = id;
	return c_count;
    end;// 
delimiter ;
