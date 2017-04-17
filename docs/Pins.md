| PMMn | PSMn | PINMODE | PULL-UP |                            Comment                            |
|:----:|:----:|:-------:|:-------:|:-------------------------------------------------------------:|
|   0  |   0  |   HI-Z  |    No   |                 HI-Z. Read values are random.                 |
|  0   |   1  |  INPUT  |   Yes   | If connected to no WRITE pins, by default read value is HIGH. |
|   1  |   0  |  WRITE  |    No   |               Writes logical zero (low voltage).              |
|   1  |   1  |  WRITE  |    No   |               Writes logical one (high voltage).              |
