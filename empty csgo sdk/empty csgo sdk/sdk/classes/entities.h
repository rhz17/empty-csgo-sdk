#pragma once

#include "../math/vector_3d.h"

#include "../../handling/utils/macros.h"
#include "../../handling/utils/netvar.h"

namespace sdk {
	namespace classes {
		enum entity_flags {
			fl_onground = (1 << 0),
			fl_ducking = (1 << 1),
			fl_waterjump = (1 << 2),
			fl_ontrain = (1 << 3),
			fl_inrain = (1 << 4),
			fl_frozen = (1 << 5),
			fl_atcontrols = (1 << 6),
			fl_client = (1 << 7),
			fl_fakeclient = (1 << 8),
			fl_inwater = (1 << 9),
			fl_fly = (1 << 10),
			fl_swim = (1 << 11),
			fl_conveyor = (1 << 12),
			fl_npc = (1 << 13),
			fl_godmode = (1 << 14),
			fl_notarget = (1 << 15),
			fl_aimtarget = (1 << 16),
			fl_partialground = (1 << 17),
			fl_staticprop = (1 << 18),
			fl_graphed = (1 << 19),
			fl_grenade = (1 << 20),
			fl_stepmovement = (1 << 21),
			fl_donttouch = (1 << 22),
			fl_basevelocity = (1 << 23),
			fl_worldbrush = (1 << 24),
			fl_object = (1 << 25),
			fl_killme = (1 << 26),
			fl_onfire = (1 << 27),
			fl_dissolving = (1 << 28),
			fl_transragdoll = (1 << 29),
			fl_unblockable_by_player = (1 << 30)
		};

		class base_general {
		public:
			// DT_BaseEntity
			get_netvar(OwnerHandle(), unsigned, "DT_BaseEntity", "m_hOwnerEntity");
			get_netvar(Spotted(), bool, "DT_BaseEntity", "m_bSpotted");
			get_netvar(FovTime(), float, "DT_BaseEntity", "m_flShadowCastDistance");
			get_netvar(Origin(), sdk::math::vector_3d, "DT_BaseEntity", "m_vecOrigin");
			get_netvar(Team(), std::int32_t, "DT_BaseEntity", "m_iTeamNum");
			get_netvar(SimulationTime(), float, "DT_BaseEntity", "m_flSimulationTime");
			get_netvar(VecMins(), sdk::math::vector_3d, "DT_BaseEntity", "m_Collision", "m_vecMins");
			get_netvar(VecMaxs(), sdk::math::vector_3d, "DT_BaseEntity", "m_Collision", "m_vecMaxs");
			get_netvar(ModelIndex(), unsigned, "DT_BaseEntity", "m_nModelIndex");

			// DT_BasePlayer
			get_netvar(ViewOffset(), sdk::math::vector_3d, "DT_BasePlayer", "localdata", "m_vecViewOffset[0]");
			get_netvar(ViewModel(), std::int32_t, "DT_BasePlayer", "m_hViewModel[0]");
			get_netvar(PunchAngle(), sdk::math::vector_3d, "DT_BasePlayer", "localdata", "m_Local", "m_viewPunchAngle");
			get_netvar(AimPunchAngle(), sdk::math::vector_3d, "DT_BasePlayer", "localdata", "m_Local", "m_aimPunchAngle");
			get_netvar(AimPunchAngleVel(), sdk::math::vector_3d, "DT_BasePlayer", "localdata", "m_Local", "m_aimPunchAngleVel");
			get_netvar(Velocity(), sdk::math::vector_3d, "DT_BasePlayer", "localdata", "m_vecVelocity[0]");
			get_netvar(MaxSpeed(), float, "DT_BasePlayer", "m_flMaxspeed");
			get_netvar(ObserverTarget(), unsigned, "DT_BasePlayer", "m_hObserverTarget");
			get_netvar(Health(), std::int32_t, "DT_BasePlayer", "m_iHealth");
			get_netvar(LifeState(), bool, "DT_BasePlayer", "m_lifeState");
			get_netvar(Flags(), entity_flags, "DT_BasePlayer", "m_fFlags");
			get_netvar(TickBase(), std::int32_t, "DT_BasePlayer", "localdata", "m_nTickBase");
			get_netvar(DuckAmount(), float, "DT_BasePlayer", "m_flDuckAmount");
			get_netvar(DuckSpeed(), float, "DT_BasePlayer", "m_flDuckSpeed");

			// DT_CSPlayer
			get_netvar(HasDefuser(), bool, "DT_CSPlayer", "m_bHasDefuser");
			get_netvar(GunGameImmunity(), bool, "DT_CSPlayer", "m_bGunGameImmunity");
			get_netvar(ShotsFired(), std::int32_t, "DT_CSPlayer", "cslocaldata", "m_iShotsFired");
			get_netvar(EyeAngles(), sdk::math::vector_3d, "DT_CSPlayer", "m_angEyeAngles");
			get_netvar(Armor(), std::int32_t, "DT_CSPlayer", "m_ArmorValue");
			get_netvar(HasHelmet(), bool, "DT_CSPlayer", "m_bHasHelmet");
			get_netvar(IsScoped(), bool, "DT_CSPlayer", "m_bIsScoped");
			get_netvar(IsDefusing(), bool, "DT_CSPlayer", "m_bIsDefusing");
			get_netvar(Money(), std::int32_t, "DT_CSPlayer", "m_iAccount");
			get_netvar(LowerBodyYawTarget(), float, "DT_CSPlayer", "m_flLowerBodyYawTarget");
			get_netvar(FlashDuration(), float, "DT_CSPlayer", "m_flFlashDuration");
			get_netvar(FlashAlpha(), float, "DT_CSPlayer", "m_flFlashMaxAlpha");
			get_netvar(HasNightVision(), float, "DT_CSPlayer", "m_bHasNightVision");
			get_netvar(NightVisionOn(), float, "DT_CSPlayer", "m_bNightVisionOn");
			get_netvar(HasHeavyArmor(), bool, "DT_CSPlayer", "m_bHasHeavyArmor");
			get_netvar(HostageAlive(), bool, "DT_CSPlayer", "m_bHostageAlive");
			get_netvar(Ragdoll(), std::int32_t, "DT_CSPlayer", "m_hRagdoll")
		};
	};
};
