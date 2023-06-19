SELECT O.ANIMAL_ID, O.NAME
from animal_outs O
left join animal_ins I
on O.animal_id = I.animal_ID
WHERE I.ANIMAL_ID IS NULL;
