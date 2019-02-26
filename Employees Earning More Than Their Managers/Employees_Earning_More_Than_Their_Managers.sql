# Write your MySQL query statement below
# Runtime: 302 ms, faster than 51.16% of MySQL online submissions for Employees Earning More Than Their Managers.
SELECT t1.Name AS Employee
FROM Employee t1, Employee t2
WHERE t1.ManagerId = t2.Id AND t1.Salary > t2.Salary;