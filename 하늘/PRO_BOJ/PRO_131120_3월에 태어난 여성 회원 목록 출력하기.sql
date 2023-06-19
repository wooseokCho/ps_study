
SELECT member_id, member_name,  gender, DATE_FORMAT(date_of_birth, '%Y-%m-%d' ) as DATE_OF_BIRTH
from member_profile
where GENDER = 'W' and DATE_FORMAT(date_of_birth, '%m' ) = 03 and tlno is not null # DATE_OF_BIRTH LIKE '%-03-%'
order by member_id ASC
