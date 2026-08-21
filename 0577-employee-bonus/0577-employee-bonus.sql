-- # Write your MySQL query statement below
-- select empId
-- from Employee
-- where empId IN(
--     select empId
--     from Bonus
--     group by empId
--     having bonus<=1000 AND bonus==NULL
-- );
--                         this wont work jamuna
select e.name ,b.bonus
from Employee e

left join Bonus b
on e.empId=b.empId
where b.bonus<1000 OR b.bonus IS null
