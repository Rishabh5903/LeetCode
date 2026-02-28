# Write your MySQL query statement below
delete p2
from Person p1
left join Person p2 on  p2.email=p1.email
where  p2.id>p1.id 