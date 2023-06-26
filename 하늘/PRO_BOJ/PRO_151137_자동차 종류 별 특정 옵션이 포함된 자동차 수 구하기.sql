SELECT c.CAR_TYPE,  count(c.car_type) as 'CARS'
FROM CAR_RENTAL_COMPANY_CAR as c 
WHERE OPTIONS LIKE '%통풍시트%'
    OR OPTIONS LIKE '%열선시트%'
    OR OPTIONS LIKE '%가죽시트%'
group by c.car_type
order by c.car_type
