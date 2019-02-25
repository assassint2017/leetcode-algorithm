# 聚合查询
# Runtime: 136 ms, faster than 48.64% of MySQL online submissions for Second Highest Salary.
# Write your MySQL query statement below

select MAX(Salary) as SecondHighestSalary 
from Employee
where Salary < (SELECT max(Salary) FROM Employee);