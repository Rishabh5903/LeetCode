# Write your MySQL query statement below
select distinct p2.email as Email 
from Person p1
join Person p2 on p1.id < p2.id
where p1.email=p2.email