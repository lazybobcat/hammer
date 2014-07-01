SLB.using(SLB);

local w = World.Instance();
local wave = 7;
local boss_tentacle = 2;

w:ShakeCameraFor(0.2);
w:AddBoss(boss_tentacle, 160);
w:AddBoss(boss_tentacle, -160);

print("Wave "..wave.." (boss) launched, good luck and SMASH'EM !");