#include "ability.h"



//Force Ability::getType() const { return forceType; }


void HydroPump::use(int evolution){
    std::cout<<"used hydropump";
}

void Earthquake::use(int evolution){
    std::cout<<"used earthquake!";
}
void AirBlow::use(int evolution){
    std::cout<<"used airblow!";
}
void FireBlast::use(int evolution){
    std::cout<<"used fireblast!";
}
void IceBeam::use(int evolution){
    std::cout<<"used ice beam!";
}
void MetalClaw::use(int evolution){
    std::cout<<"used metal claw!";
}
