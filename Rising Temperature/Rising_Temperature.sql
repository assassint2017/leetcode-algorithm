-- Runtime: 292 ms, faster than 96.57% of MySQL online submissions for Rising Temperature.
-- Write your MySQL query statement below
SELECT w1.Id
FROM Weather w1, Weather w2
WHERE w1.Temperature > w2.Temperature AND TO_DAYS(w1.RecordDate) - TO_DAYS(w2.RecordDate) = 1