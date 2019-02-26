# Write your MySQL query statement below
# Runtime: 206 ms, faster than 29.08% of MySQL online submissions for Duplicate Emails.
select Email from Person group by Email having count(distinct Id) > 1;