# Write your MySQL query statement below
SELECT e1.name as Employee
FROM employee e1
INNER JOIN employee e2 ON e2.id = e1.managerID
WHERE
e1.salary > e2.salary