# Write your MySQL query statement below
select name as Customers
from Customers c
left join orders o on o.customerId = c.id
where o.customerid is NULL