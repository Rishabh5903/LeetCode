# Write your MySQL query statement below
-- SELECT e2.name as Employee
-- FROM employee e1
-- INNER JOIN employee e2 ON e1.id = e2.managerID
-- WHERE
-- e1.salary < e2.salary

select e2.name as Employee from employee e1 join employee e2 on e1.id = e2.managerid where e2.salary>e1.salary;