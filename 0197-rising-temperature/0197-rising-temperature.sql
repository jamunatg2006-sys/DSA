# Write your MySQL query statement below
select w1.id
from Weather w1

join Weather w2
ON w1.recordDate=DATE_ADD(w2.recordDate, INTERVAl 1 DAY)
WHERE w1.temperature> w2.temperature;