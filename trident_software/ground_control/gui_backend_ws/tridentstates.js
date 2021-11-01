/*
    NOTE: these states need to match with /trident_software/baseclasses/tridentstates.py
*/
module.exports =  {
    missionControlState: {
        NO_MISSION: 0,
        MISSION_LOADED: 1,
        EXECUTING_MISSION: 2,
        MISSION_FINISHED: 3
    },
    
    guidanceState: {
        IDLE: 1,
        PREPARING_GUIDANCE: 2,
        GUIDING: 3 //Pinging
    },
    
    navigationState: {
        IDLE: 0,
        EXECUTING: 1
    },
    
    motorControlState: {
        IDLE: 0,
        EXECUTING: 1,
        MANUAL_OVERRIDE: 2
    },
    
    motorDriverSTate: {
        IDLE: 0,
        KILLED: 1,
        MOTOR_OUTPUT_SILENCE: 2,
        ACTIVE: 3
    }
}
