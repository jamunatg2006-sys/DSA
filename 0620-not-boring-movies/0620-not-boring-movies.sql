# Write your MySQL query statement below
select *
from Cinema
Where description != 'boring' AND
  id %2 !=0 
--   takes only odd number
order by rating DESC
