SELECT name, count(name) as COUNT
from animal_ins
group by name 
having COUNT >=2 AND NAME IS NOT NULL
order by NAME;
