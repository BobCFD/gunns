/**
@file  GunnShowThermalTest.cpp
@brief GunnShowThermalTest GUNNS Basic Network implementation.

@copyright  Copyright 2019 United States Government as represented by the Administrator of the
            National Aeronautics and Space Administration. All Rights Reserved.

LIBRARY DEPENDENCY:
(
  (aspects/thermal/GunnsThermalCapacitor.o)
  (aspects/thermal/GunnsThermalHeater.o)
  (aspects/thermal/GunnsThermalPanel.o)
  (aspects/thermal/GunnsThermalPotential.o)
  (aspects/thermal/GunnsThermalRadiation.o)
  (aspects/thermal/GunnsThermalSource.o)
  (core/GunnsBasicConductor.o)
  (core/GunnsBasicExternalDemand.o)
  (core/GunnsBasicExternalSupply.o)
  (core/network/GunnsNetworkBase.o)
)

PROGRAMMERS:
  ((Auto-generated by the GunnsDraw netexport script version beta 13) (2019-12-11 07:14:44.171833))
*/

#include "GunnShowThermalTest.hh"
#include "simulation/hs/TsHsMsg.hh"
#include "software/exceptions/TsInitializationException.hh"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @param[in] name    (--) Name of the network for H&S messages.
/// @param[in] network (--) Pointer to the main network object.
/// 
/// @details  Default constructs the GunnShowThermalTest Network Config Data.
////////////////////////////////////////////////////////////////////////////////////////////////////
GunnShowThermalTestConfigData::GunnShowThermalTestConfigData(const std::string& name, GunnShowThermalTest* network)
    :
    netSolver(name + ".netSolver", 1.0000, 0.001, 1, 1),
    // Spotter Config Data
    // Link Config Data
    conductor(name + ".conductor", &network->netNodeList, 1.0E7),
    externalDemand(name + ".externalDemand", &network->netNodeList, 0.0, 1.0, 1.0E-08, 0.05),
    externalSupply(name + ".externalSupply", &network->netNodeList),
    radiation(name + ".radiation", &network->netNodeList, 1.0E-3),
    potential(name + ".potential", &network->netNodeList, 1.0E7),
    capacitor(name + ".capacitor", &network->netNodeList, -1),
    panel(name + ".panel", &network->netNodeList, 1.0, 0, 0.5, 1.0),
    heater(name + ".heater", &network->netNodeList, 1.0, 0),
    source(name + ".source", &network->netNodeList, 1.0, 0)
{
    // Load config data vectors
    {
        const double array[] = {0.1, 0.9};
        panel.cFluxDistributionFractions.assign(array, array + sizeof(array) / sizeof(double));
    }
    {
        const double array[] = {1.0};
        heater.cFluxDistributionFractions.assign(array, array + sizeof(array) / sizeof(double));
    }
    {
        const double array[] = {0.3, 0.3, 0.0, 0.0, 0.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        source.cFluxDistributionFractions.assign(array, array + sizeof(array) / sizeof(double));
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Default destructs the GunnShowThermalTest Network Config Data.
////////////////////////////////////////////////////////////////////////////////////////////////////
GunnShowThermalTestConfigData::~GunnShowThermalTestConfigData()
{
    // Nothing to do
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @param[in] network (--) Pointer to the main network object.
///
/// @details  Default constructs the GunnShowThermalTest Network Input Data.
////////////////////////////////////////////////////////////////////////////////////////////////////
GunnShowThermalTestInputData::GunnShowThermalTestInputData(GunnShowThermalTest* network)
    :
    // Spotter Input Data
    // Link Input Data
    conductor(false, 0.0),
    externalDemand(false, 0.0, 0.0),
    externalSupply(false, 0.0, 0.0),
    radiation(false, 0.0, 1.0),
    potential( false,  0.0, 295.0),
    capacitor(false, 0.0, 1000.0, 295.0, false, GunnsThermalCapacitorInputData::DEFAULT_TEMPERATURE),
    panel(false, 0.0, 0.0, false, 0.0),
    heater(false, 0.0, 0.0, false, 0.0),
    source(false, 0.0, 1.0, false, 0.0)
{
    // Load input data vectors
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Default destructs the GunnShowThermalTest Network Input Data.
////////////////////////////////////////////////////////////////////////////////////////////////////
GunnShowThermalTestInputData::~GunnShowThermalTestInputData()
{
    // Nothing to do
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @param[in] name (--) Name of the network for H&S messages.
///
/// @details  Default constructs the GunnShowThermalTest Network.
////////////////////////////////////////////////////////////////////////////////////////////////////
GunnShowThermalTest::GunnShowThermalTest(const std::string& name)
    :
    GunnsNetworkBase(name, N_NODES, netNodes),
    netNodes(),
    netConfig(name, this),
    netInput(this),
    // Data Tables 
    // Spotters
    // Links
    conductor(),
    externalDemand(),
    externalSupply(),
    radiation(),
    potential(),
    capacitor(),
    panel(),
    heater(),
    source()
{
    // Nothing to do
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details Default destructs the GunnShowThermalTest Network.
////////////////////////////////////////////////////////////////////////////////////////////////////
GunnShowThermalTest::~GunnShowThermalTest()
{
    // Nothing to do
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @param[in] name (--) Name of the network for H&S messages.
///
/// @details  Initializes the nodes with their config and input data objects.  The nodes are
///           initialized through the node list object, which may point to this network's nodes
///           (when this is a standalone network), or the super-network's nodes (as a sub-network).
////////////////////////////////////////////////////////////////////////////////////////////////////
void GunnShowThermalTest::initNodes(const std::string& name)
{
    /// - Initialize the nodes.
    netNodeList.mNodes[0 + netSuperNodesOffset].initialize(name + createNodeName(0 + netSuperNodesOffset), 295.0);
    netNodeList.mNodes[1 + netSuperNodesOffset].initialize(name + createNodeName(1 + netSuperNodesOffset), 295.0);
    netNodeList.mNodes[2 + netSuperNodesOffset].initialize(name + createNodeName(2 + netSuperNodesOffset), 294.261);
    netNodeList.mNodes[3 + netSuperNodesOffset].initialize(name + createNodeName(3 + netSuperNodesOffset), 294.261);
    netNodeList.mNodes[4 + netSuperNodesOffset].initialize(name + createNodeName(4 + netSuperNodesOffset), 294.261);
    netNodeList.mNodes[5 + netSuperNodesOffset].initialize(name + createNodeName(5 + netSuperNodesOffset), 294.261);
    netNodeList.mNodes[6 + netSuperNodesOffset].initialize(name + createNodeName(6 + netSuperNodesOffset), 294.261);
    netNodeList.mNodes[7 + netSuperNodesOffset].initialize(name + createNodeName(7 + netSuperNodesOffset), 294.261);
    netNodeList.mNodes[8 + netSuperNodesOffset].initialize(name + createNodeName(8 + netSuperNodesOffset), 294.261);
    netNodeList.mNodes[9 + netSuperNodesOffset].initialize(name + createNodeName(9 + netSuperNodesOffset), 294.261);
    netNodeList.mNodes[10 + netSuperNodesOffset].initialize(name + createNodeName(10 + netSuperNodesOffset), 294.261);
    netNodeList.mNodes[11 + netSuperNodesOffset].initialize(name + createNodeName(11 + netSuperNodesOffset), 294.261);
    netNodeList.mNodes[12 + netSuperNodesOffset].initialize(name + createNodeName(12 + netSuperNodesOffset), 294.261);
    /// - Only init the Ground node if this is not a sub-network.
    if (!netIsSubNetwork) {
        netNodeList.mNodes[13].initialize(name + ".GROUND");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Initializes this network's links, spotters and solver with their config and input data
///           objects.
////////////////////////////////////////////////////////////////////////////////////////////////////
void GunnShowThermalTest::initNetwork()
{
    const int groundOffset = netNodeList.mNumNodes - N_NODES;

    /// - Register sockets with the jumper plugs.

    /// - Initialize the links.
    netLinks.clear();
    conductor.initialize(netConfig.conductor, netInput.conductor, netLinks, Node0 + netSuperNodesOffset, Node1 + netSuperNodesOffset);
    externalDemand.initialize(netConfig.externalDemand, netInput.externalDemand, netLinks, GROUND + groundOffset, Node2 + netSuperNodesOffset);
    externalSupply.initialize(netConfig.externalSupply, netInput.externalSupply, netLinks, Node1 + netSuperNodesOffset, GROUND + groundOffset);
    radiation.initialize(netConfig.radiation, netInput.radiation, netLinks, Node2 + netSuperNodesOffset, Node3 + netSuperNodesOffset);
    potential.initialize(netConfig.potential, netInput.potential, netLinks, GROUND + groundOffset, Node0 + netSuperNodesOffset);
    capacitor.initialize(netConfig.capacitor, netInput.capacitor, netLinks, Node1 + netSuperNodesOffset, GROUND + groundOffset);
    {
        const int array[] = {Node7 + netSuperNodesOffset, Node4 + netSuperNodesOffset};
        std::vector<int> vector (array, array + sizeof(array) / sizeof(int));
        panel.initialize(netConfig.panel, netInput.panel, netLinks, &vector);
    }
    {
        const int array[] = {Node8 + netSuperNodesOffset};
        std::vector<int> vector (array, array + sizeof(array) / sizeof(int));
        heater.initialize(netConfig.heater, netInput.heater, netLinks, &vector);
    }
    {
        const int array[] = {Node1 + netSuperNodesOffset, Node2 + netSuperNodesOffset, Node6 + netSuperNodesOffset, Node12 + netSuperNodesOffset, Node5 + netSuperNodesOffset, Node3 + netSuperNodesOffset, Node10 + netSuperNodesOffset, Node8 + netSuperNodesOffset, Node11 + netSuperNodesOffset, Node7 + netSuperNodesOffset, Node9 + netSuperNodesOffset, Node4 + netSuperNodesOffset};
        std::vector<int> vector (array, array + sizeof(array) / sizeof(int));
        source.initialize(netConfig.source, netInput.source, netLinks, &vector);
    }

    /// - Initialize the spotters.

    /// - Initialize the solver, only if this is not a sub-network.
    if (!netIsSubNetwork) {
        netSolver.initializeNodes(netNodeList);
        netSolver.initialize(netConfig.netSolver, netLinks);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @param[in] timeStep (s) Integration time step.
///
/// @details  Updates this network's spotters before solving the network.
////////////////////////////////////////////////////////////////////////////////////////////////////
void GunnShowThermalTest::stepSpottersPre(const double timeStep)
{
    /// - Step network spotters prior to solver step.
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @param[in]   timeStep (s) Integration time step.
///
/// @details  Updates this network's spotters after solving the network.
////////////////////////////////////////////////////////////////////////////////////////////////////
void GunnShowThermalTest::stepSpottersPost(const double timeStep)
{
    /// - Step network spotters after solver step.
}
