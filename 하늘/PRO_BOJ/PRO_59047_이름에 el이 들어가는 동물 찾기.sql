SELECT animal_id, name
from animal_ins a
where animal_type = 'Dog' and name regexp 'el'
order by name;
