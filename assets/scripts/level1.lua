SLB.using(SLB);

local w = World.Instance();
local wave = 1;
local rabbit = 1; 
local tentacle = 2;

w:AddCreature(rabbit, 412);
w:AddCreature(tentacle, 1000);
w:AddCreature(tentacle, -1100);
w:AddCreature(tentacle, 1400);
w:AddCreature(tentacle, -1500);
w:AddCreature(tentacle, 1600);
w:AddCreature(tentacle, -1700);
w:AddCreature(tentacle, 1800);

w:AddCreature(rabbit, 1650);

w:AddCreature(tentacle, 2000);
w:AddCreature(tentacle, 2100);
w:AddCreature(tentacle, 2200);
w:AddCreature(tentacle, 2300);
w:AddCreature(tentacle, -2000);
w:AddCreature(tentacle, -2100);
w:AddCreature(tentacle, -2200);
w:AddCreature(tentacle, -2300);

print("Wave "..wave.." launched, good luck and SMASH'EM !");