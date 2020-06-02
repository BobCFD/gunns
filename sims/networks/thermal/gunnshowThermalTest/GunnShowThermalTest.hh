#ifndef GunnShowThermalTest_EXISTS
#define GunnShowThermalTest_EXISTS

/**
@file  GunnShowThermalTest.hh
@brief GunnShowThermalTest GUNNS Basic Network declarations.

@copyright  Copyright 2019 United States Government as represented by the Administrator of the
            National Aeronautics and Space Administration. All Rights Reserved.

@defgroup  GUNNS_GUNNSHOWTHERMALTEST GunnShowThermalTest GUNNS Basic Network
@ingroup  GUNNS

@details
PURPOSE: (Provides classes for the GunnShowThermalTest GUNNS Basic Network.)

REFERENCES:
  ()

ASSUMPTIONS AND LIMITATIONS:
  ()

LIBRARY DEPENDENCY:
  ((GunnShowThermalTest.o))

PROGRAMMERS:
  ((Auto-generated by the GunnsDraw netexport script version beta 13) (2019-12-11 07:14:44.171833))

@{
*/

#include "software/SimCompatibility/TsSimCompatibility.hh"
#include "core/network/GunnsNetworkBase.hh"
#include "aspects/thermal/GunnsThermalCapacitor.hh"
#include "aspects/thermal/GunnsThermalHeater.hh"
#include "aspects/thermal/GunnsThermalPanel.hh"
#include "aspects/thermal/GunnsThermalPotential.hh"
#include "aspects/thermal/GunnsThermalRadiation.hh"
#include "aspects/thermal/GunnsThermalSource.hh"
#include "core/GunnsBasicConductor.hh"
#include "core/GunnsBasicExternalDemand.hh"
#include "core/GunnsBasicExternalSupply.hh"

// Forward-declare the main network class for use in the config data.
class GunnShowThermalTest;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief    GunnShowThermalTest GUNNS Network Config Data
///
/// @details  Configuration data class for the GunnShowThermalTest Network.
////////////////////////////////////////////////////////////////////////////////////////////////////
class GunnShowThermalTestConfigData
{
    public:
        // Solver configuration data
        GunnsConfigData netSolver;    /**< (--) trick_chkpnt_io(**) Network solver config data. */ 
        // Spotters configuration data
        // Links configuration data
        GunnsBasicConductorConfigData conductor;    /**< (--) trick_chkpnt_io(**) conductor config data. */
        GunnsBasicExternalDemandConfigData externalDemand;    /**< (--) trick_chkpnt_io(**) externalDemand config data. */
        GunnsBasicExternalSupplyConfigData externalSupply;    /**< (--) trick_chkpnt_io(**) externalSupply config data. */
        GunnsThermalRadiationConfigData radiation;    /**< (--) trick_chkpnt_io(**) radiation config data. */
        GunnsThermalPotentialConfigData potential;    /**< (--) trick_chkpnt_io(**) potential config data. */
        GunnsThermalCapacitorConfigData capacitor;    /**< (--) trick_chkpnt_io(**) capacitor config data. */
        GunnsThermalPanelConfigData panel;    /**< (--) trick_chkpnt_io(**) panel config data. */
        GunnsThermalHeaterConfigData heater;    /**< (--) trick_chkpnt_io(**) heater config data. */
        GunnsThermalSourceConfigData source;    /**< (--) trick_chkpnt_io(**) source config data. */
        /// @brief  Default constructs this network configuration data.
        GunnShowThermalTestConfigData(const std::string& name, GunnShowThermalTest* network);
        /// @brief  Default destructs this network configuration data.
        virtual ~GunnShowThermalTestConfigData();

    private:
        /// @details  Copy constructor unavailable since declared private and not implemented.
        GunnShowThermalTestConfigData(const GunnShowThermalTestConfigData&);
        /// @details  Assignment operator unavailable since declared private and not implemented.
        GunnShowThermalTestConfigData& operator =(const GunnShowThermalTestConfigData&);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief    GunnShowThermalTest GUNNS Network Input Data
///
/// @details  Input data class for the GunnShowThermalTest Network.
////////////////////////////////////////////////////////////////////////////////////////////////////
class GunnShowThermalTestInputData
{
    public:
        // Spotters input data
        // Links input data
        GunnsBasicConductorInputData conductor;    /**< (--) trick_chkpnt_io(**) conductor input data. */
        GunnsBasicExternalDemandInputData externalDemand;    /**< (--) trick_chkpnt_io(**) externalDemand input data. */
        GunnsBasicExternalSupplyInputData externalSupply;    /**< (--) trick_chkpnt_io(**) externalSupply input data. */
        GunnsThermalRadiationInputData radiation;    /**< (--) trick_chkpnt_io(**) radiation input data. */
        GunnsThermalPotentialInputData potential;    /**< (--) trick_chkpnt_io(**) potential input data. */
        GunnsThermalCapacitorInputData capacitor;    /**< (--) trick_chkpnt_io(**) capacitor input data. */
        GunnsThermalPanelInputData panel;    /**< (--) trick_chkpnt_io(**) panel input data. */
        GunnsThermalHeaterInputData heater;    /**< (--) trick_chkpnt_io(**) heater input data. */
        GunnsThermalSourceInputData source;    /**< (--) trick_chkpnt_io(**) source input data. */
        /// @brief  Default constructs this network input data.
        GunnShowThermalTestInputData(GunnShowThermalTest* network);
        /// @brief  Default destructs this network input data.
        virtual ~GunnShowThermalTestInputData();

    private:
        /// @details  Copy constructor unavailable since declared private and not implemented.
        GunnShowThermalTestInputData(const GunnShowThermalTestInputData&);
        /// @details  Assignment operator unavailable since declared private and not implemented.
        GunnShowThermalTestInputData& operator =(const GunnShowThermalTestInputData&);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief    GunnShowThermalTest GUNNS Network
///
/// @details  Main class for the GunnShowThermalTest Network.
////////////////////////////////////////////////////////////////////////////////////////////////////
class GunnShowThermalTest : public GunnsNetworkBase
{
    TS_MAKE_SIM_COMPATIBLE(GunnShowThermalTest);
    public:
        /// @brief  Enumeration of the GunnShowThermalTest Network nodes.
        enum Nodes
        {
            Node0 = 0,    ///< Node 0
            Node1 = 1,    ///< Node 1
            Node2 = 2,    ///< Node 2
            Node3 = 3,    ///< Node 3
            Node4 = 4,    ///< Node 4
            Node5 = 5,    ///< Node 5
            Node6 = 6,    ///< Node 6
            Node7 = 7,    ///< Node 7
            Node8 = 8,    ///< Node 8
            Node9 = 9,    ///< Node 9
            Node10 = 10,    ///< Node 10
            Node11 = 11,    ///< Node 11
            Node12 = 12,    ///< Node 12
            GROUND = 13,    ///< Ground Node
            N_NODES = 14    ///< Number of nodes including Ground
        };
        // Network declarations
        GunnsBasicNode netNodes[GunnShowThermalTest::N_NODES];    /**< (--) Network nodes array. */
        GunnShowThermalTestConfigData netConfig;    /**< (--) trick_chkpnt_io(**) Network config data. */
        GunnShowThermalTestInputData netInput;    /**< (--) trick_chkpnt_io(**) Network input data. */
        // Data Tables
        // Spotters
        // Links
        GunnsBasicConductor conductor;    /**< (--) conductor instance. */
        GunnsBasicExternalDemand externalDemand;    /**< (--) externalDemand instance. */
        GunnsBasicExternalSupply externalSupply;    /**< (--) externalSupply instance. */
        GunnsThermalRadiation radiation;    /**< (--) radiation instance. */
        GunnsThermalPotential potential;    /**< (--) potential instance. */
        GunnsThermalCapacitor capacitor;    /**< (--) capacitor instance. */
        GunnsThermalPanel panel;    /**< (--) panel instance. */
        GunnsThermalHeater heater;    /**< (--) heater instance. */
        GunnsThermalSource source;    /**< (--) source instance. */
        /// @brief  Default constructs this network.
        GunnShowThermalTest(const std::string& name = "");
        /// @brief  Default destructs this network.
        virtual ~GunnShowThermalTest();
        /// @brief  Network nodes initialization task.
        virtual void initNodes(const std::string& name);
        /// @brief  Network links & spotters initialization task.
        virtual void initNetwork();
        /// @brief  Update network spotters before the solver solution.
        virtual void stepSpottersPre(const double timeStep);
        /// @brief  Update network spotters after the solver solution.
        virtual void stepSpottersPost(const double timeStep);

    private:
        /// @details  Copy constructor unavailable since declared private and not implemented.
        GunnShowThermalTest(const GunnShowThermalTest&);
        /// @details  Assignment operator unavailable since declared private and not implemented.
        GunnShowThermalTest& operator =(const GunnShowThermalTest&);
};

/// @}  

#endif
