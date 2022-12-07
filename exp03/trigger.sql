Delimiter $$
CREATE TRIGGER trg_tb_student_insert_check BEFORE INSERT
ON S FOR EACH ROW
BEGIN
	DECLARE msg varchar(100);
 
	IF NEW.age <= 0 OR NEW.age >= 200 
	THEN
		SET msg = CONCAT('您输入的年龄值：',NEW.age,' 为无效的年龄，请输入0到100以内的有效数字。');
		SIGNAL SQLSTATE 'HY000' SET MESSAGE_TEXT = msg;
	END IF;
END; $$
Delimiter ;