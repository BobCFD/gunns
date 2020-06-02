/************************** TRICK HEADER ***********************************************************
@copyright Copyright 2019 United States Government as represented by the Administrator of the
           National Aeronautics and Space Administration.  All Rights Reserved.
 LIBRARY DEPENDENCY:
    ((aspects/electrical/Switch/GunnsElectConstantPowerUserLoad.o))
***************************************************************************************************/

#include "UtGunnsElectConstantPowerUserLoad.hh"

#include "software/exceptions/TsInitializationException.hh"
#include "strings/UtResult.hh"

/// @details  Test identification number.
int UtGunnsElectConstantPowerUserLoad::TEST_ID = 0;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Default constructs this GUNNS Electrical Constant-Power User Load Spotter link model unit test.
////////////////////////////////////////////////////////////////////////////////////////////////////
UtGunnsElectConstantPowerUserLoad::UtGunnsElectConstantPowerUserLoad()
    :
    CppUnit::TestFixture(),
    tName(""),
    tUnderVoltageLimit(0.0),
    tPowerNormal(0.0),
    tPowerStandby(0.0),
    tConfigData(0),
    tInitialMode(0),
    tInitialVoltage(0.0),
    tInputData(0),
    tArticle(0)
{
    // nothing to do
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Default destructs this GUNNS Electrical Constant-Power User Load Spotter link model unit test.
////////////////////////////////////////////////////////////////////////////////////////////////////
UtGunnsElectConstantPowerUserLoad::~UtGunnsElectConstantPowerUserLoad()
{
    // nothing to do
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Executed before each unit test as part of the CPPUNIT framework.
////////////////////////////////////////////////////////////////////////////////////////////////////

void UtGunnsElectConstantPowerUserLoad::setUp()
{
    /// - Define the nominal configuration data.
    tName              = "nominal";
    tUnderVoltageLimit = 100.0;
    tPowerNormal       = 40.0;
    tPowerStandby      = 500.0;
    tConfigData        = new GunnsElectConstantPowerUserLoadConfigData(tName,
                                                                       tUnderVoltageLimit,
                                                                       tPowerNormal,
                                                                       tPowerStandby);

    /// - Define the nominal input data.
    tInitialMode       = 1;
    tInitialVoltage    = 120.0;
    tInputData         = new GunnsElectConstantPowerUserLoadInputData(tInitialMode,
                                                                      tInitialVoltage);

    /// - Default construct the nominal test article.
    tArticle           = new FriendlyGunnsElectConstantPowerUserLoad(tConfigData, tInputData);

    /// - Increment the test identification number.
    ++TEST_ID;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Executed after each unit test as part of the CPPUNIT framework.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UtGunnsElectConstantPowerUserLoad::tearDown()
{
    /// - Deletes for news (in reverse order) in setUp.
    delete tArticle;
    delete tInputData;
    delete tConfigData;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Tests for GUNNS Electrical Constant-Power User Load Spotter construction of configuration.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UtGunnsElectConstantPowerUserLoad::testConfig()
{
    UT_RESULT_FIRST;

    /// @test    Configuration data nominal construction.
    CPPUNIT_ASSERT(tName              == tConfigData->mName);
    CPPUNIT_ASSERT(tUnderVoltageLimit == tConfigData->mUnderVoltageLimit);
    CPPUNIT_ASSERT(tPowerNormal       == tConfigData->mPowerNormal);
    CPPUNIT_ASSERT(tPowerStandby      == tConfigData->mPowerStandby);

    UT_PASS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Tests for GUNNS Electrical Constant-Power User Load Spotter construction of input data.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UtGunnsElectConstantPowerUserLoad::testInput()
{
    UT_RESULT;

    /// @test    Input data nominal construction.
    CPPUNIT_ASSERT(tInitialMode    == tInputData->mInitialMode);
    CPPUNIT_ASSERT(tInitialVoltage == tInputData->mInitialVoltage);

    UT_PASS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Tests for GUNNS Electrical Constant-Power User Load Spotter default construction.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UtGunnsElectConstantPowerUserLoad::testDefaultConstruction()
{
    UT_RESULT;

    /// @test    Default construction of attributes.
    FriendlyGunnsElectConstantPowerUserLoad* article = new FriendlyGunnsElectConstantPowerUserLoad();
    CPPUNIT_ASSERT(""   == article->mName);
    CPPUNIT_ASSERT(0.0  == article->mSupplyVoltage);
    CPPUNIT_ASSERT(0    == article->mConfig);
    CPPUNIT_ASSERT(0    == article->mInput);
    CPPUNIT_ASSERT(!article->mLoad.isInitialized());

    /// @test    Default construction of initialization flag.
    CPPUNIT_ASSERT(!article->isInitialized());

    /// @test    New/delete for code coverage.
    delete article;

    UT_PASS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Tests for GUNNS Electrical Constant-Power User Load Spotter nominal construction.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UtGunnsElectConstantPowerUserLoad::testNominalConstruction()
{
    UT_RESULT;

    /// @test    Nominal construction of attributes.
    CPPUNIT_ASSERT(""          == tArticle->mName);
    CPPUNIT_ASSERT(0.0         == tArticle->mSupplyVoltage);
    CPPUNIT_ASSERT(tConfigData == tArticle->mConfig);
    CPPUNIT_ASSERT(tInputData  == tArticle->mInput);
    CPPUNIT_ASSERT(!tArticle->mLoad.isInitialized());

    /// @test    Default construction of initialization flag.
    CPPUNIT_ASSERT(!tArticle->isInitialized());

    UT_PASS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Tests for GUNNS Electrical Constant-Power User Load Spotter initialization method.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UtGunnsElectConstantPowerUserLoad::testNominalInitialization()
{
    UT_RESULT;

    /// @test    Nominal initialization of config & input data.
    FriendlyGunnsElectConstantPowerUserLoad article;
    CPPUNIT_ASSERT_NO_THROW(article.initialize(tConfigData, tInputData));
    CPPUNIT_ASSERT(0.0         == article.mSupplyVoltage);
    CPPUNIT_ASSERT(tConfigData == article.mConfig);
    CPPUNIT_ASSERT(tInputData  == article.mInput);

    UT_PASS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Tests for GUNNS Electrical Constant-Power User Load Spotter nominal initLoad method.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UtGunnsElectConstantPowerUserLoad::testNominalInitLoad()
{
    UT_RESULT;

    /// @test    Nominal initialization of spotter and user load.
    CPPUNIT_ASSERT_NO_THROW(tArticle->initLoad());
    CPPUNIT_ASSERT(tConfigData     == tArticle->mConfig);
    CPPUNIT_ASSERT(tInputData      == tArticle->mInput);
    CPPUNIT_ASSERT(tName           == tArticle->mName);
    CPPUNIT_ASSERT(tInitialVoltage == tArticle->mSupplyVoltage);
    CPPUNIT_ASSERT(tArticle->mLoad.isInitialized());
    CPPUNIT_ASSERT(tArticle->mLoad.getPowerValid());
    CPPUNIT_ASSERT(tArticle->isInitialized());

    /// @test    Double initialization since this is likely to happen often.
    CPPUNIT_ASSERT_NO_THROW(tArticle->initLoad());
    CPPUNIT_ASSERT(tConfigData     == tArticle->mConfig);
    CPPUNIT_ASSERT(tInputData      == tArticle->mInput);
    CPPUNIT_ASSERT(tName           == tArticle->mName);
    CPPUNIT_ASSERT(tInitialVoltage == tArticle->mSupplyVoltage);
    CPPUNIT_ASSERT(tArticle->mLoad.isInitialized());
    CPPUNIT_ASSERT(tArticle->mLoad.getPowerValid());
    CPPUNIT_ASSERT(tArticle->isInitialized());

    UT_PASS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Tests for GUNNS Electrical Constant-Power User Load Spotter access methods.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UtGunnsElectConstantPowerUserLoad::testAccessors()
{
    UT_RESULT;

    /// @test    getLoad method.
    CPPUNIT_ASSERT(&tArticle->mLoad == tArticle->getLoad());

    UT_PASS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Tests for GUNNS Electrical Constant-Power User Load Spotter step methods.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UtGunnsElectConstantPowerUserLoad::testStep()
{
    UT_RESULT;

    /// @test    Spotter stepPreSolver and stepPostSolver methods do nothing (nothing to verify,
    ///          just call for coverage).
    tArticle->stepPreSolver(0.0);
    tArticle->stepPostSolver(0.0);

    /// @test    step method steps the contained load with the given supply voltage.
    CPPUNIT_ASSERT(tArticle->getLoad()->getPowerValid());
    tArticle->setSupplyVoltage(0.0);
    CPPUNIT_ASSERT(0.0 == tArticle->mSupplyVoltage);
    tArticle->step();
    CPPUNIT_ASSERT(!tArticle->getLoad()->getPowerValid());

    UT_PASS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @details  Tests for GUNNS Electrical Constant-Power User Load Spotter initialization exceptions.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UtGunnsElectConstantPowerUserLoad::testInitializationExceptions()
{
    UT_RESULT;

    /// @test    Exception from bad spotter config & input data types.
    BadGunnsElectConstantPowerUserLoadConfigData badConfig("bad");
    BadGunnsElectConstantPowerUserLoadInputData badInput;
    CPPUNIT_ASSERT_THROW(tArticle->initialize(&badConfig,  tInputData), TsInitializationException);
    CPPUNIT_ASSERT_THROW(tArticle->initialize(tConfigData,  &badInput), TsInitializationException);
    CPPUNIT_ASSERT_THROW(tArticle->initialize(&badConfig,   &badInput), TsInitializationException);

    /// @test    Exception thrown from user load initialization.
    tConfigData->mPowerNormal = -10.0;
    tArticle->initialize(tConfigData, tInputData);
    CPPUNIT_ASSERT_THROW(tArticle->initLoad(), TsInitializationException);
    CPPUNIT_ASSERT(!tArticle->isInitialized());

    UT_PASS_LAST;
}
