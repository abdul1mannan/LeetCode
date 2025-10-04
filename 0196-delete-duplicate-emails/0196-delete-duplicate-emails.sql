DELETE p
FROM Person as p
JOIN (
  SELECT email, MIN(id) AS keep_id
  FROM Person
  GROUP BY email
) as k
  ON p.email = k.email
WHERE p.id > k.keep_id;
