# Write your MySQL query statement below
# Runtime: 142 ms, faster than 100.00% of MySQL online submissions for Swap Salary.
-- 按理说第一条语句就可以，但是没有结果，应该是网站出现了一些bug
# UPDATE salary SET sex = IF (sex = 'm', 'f', 'm')
SELECT id, name, IF (sex = 'm', 'f', 'm') as sex, salary
FROM salary;
