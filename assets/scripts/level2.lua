SLB.using(SLB);

local w = World.Instance();
local wave = 2;
local rabbit = 1; 
local tentacle = 2;
local crawler = 3;

w:AddCreature(crawler, 10);
w:AddCreature(crawler, -10);
w:AddCreature(crawler, 100);
w:AddCreature(crawler, -100);
w:AddCreature(rabbit, 300);

w:AddCreature(crawler, 250);
w:AddCreature(tentacle, 450);
w:AddCreature(tentacle, 520);
w:AddCreature(tentacle, 590);
w:AddCreature(tentacle, 650);
w:AddCreature(tentacle, 720);

w:AddCreature(crawler, -350);
w:AddCreature(tentacle, -630);
w:AddCreature(tentacle, -700);
w:AddCreature(tentacle, -770);
w:AddCreature(tentacle, -850);
w:AddCreature(tentacle, -920);
w:AddCreature(rabbit, -900);

w:AddCreature(crawler, 750);
w:AddCreature(crawler, -750);
w:AddCreature(crawler, 850);
w:AddCreature(crawler, -850);
w:AddCreature(crawler, 950);
w:AddCreature(crawler, -950);
w:AddCreature(crawler, 1050);
w:AddCreature(crawler, -1050);
w:AddCreature(tentacle, 1350);
w:AddCreature(tentacle, 1450);
w:AddCreature(tentacle, 1550);
w:AddCreature(tentacle, 1650);
w:AddCreature(tentacle, 1750);
w:AddCreature(tentacle, 1850);
w:AddCreature(tentacle, -1350);
w:AddCreature(tentacle, -1450);
w:AddCreature(tentacle, -1550);
w:AddCreature(tentacle, -1650);
w:AddCreature(tentacle, -1750);
w:AddCreature(tentacle, -1850);


print("Wave "..wave.." launched, good luck and SMASH'EM !");