select date_format(DATETIME, "%H") as 'HOUR', count(DATETIME) as 'COUNT'
from animal_outs
group by HOUR
having HOUR >=09 AND HOUR <20
order by HOUR
