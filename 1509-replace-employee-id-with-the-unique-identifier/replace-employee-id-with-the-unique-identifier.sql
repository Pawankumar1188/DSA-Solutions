# Write your MySQL query statement below
select EmployeeUNI.unique_id , Employees.name
from Employees
LEFT JOIN EmployeeUNI
ON EmployeeUNI.ID=Employees.ID

