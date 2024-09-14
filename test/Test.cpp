///                                                                           
/// Langulus::Module::UMS                                                     
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "Main.hpp"
#include <Langulus/User.hpp>                          
#include <catch2/catch.hpp>


/// See https://github.com/catchorg/Catch2/blob/devel/docs/tostring.md        
CATCH_TRANSLATE_EXCEPTION(::Langulus::Exception const& ex) {
   const Text serialized {ex};
   return ::std::string {Token {serialized}};
}

SCENARIO("Main testing scenario for UMS", "[UMS]") {
   static Allocator::State memoryState;
   
   for (int repeat = 0; repeat != 10; ++repeat) {
      GIVEN(std::string("Init and shutdown cycle #") + std::to_string(repeat)) {
         // Create root entity                                          
         auto root = Thing::Root<false>("UMS");

         WHEN("Components created via abstractions (not mandatory)") {
            auto unit = root.CreateUnit<A::User>();

            // Update once                                              
            root.Update({});
            root.DumpHierarchy();

            REQUIRE(unit.GetCount() == 1);
            REQUIRE(unit.CastsTo<A::User>(1));
            REQUIRE(unit.IsSparse());

            REQUIRE(root.GetUnits().GetCount() == 1);
         }

         WHEN("Components created via tokens (mandatory)") {
            auto unit = root.CreateUnitToken("A::User");

            // Update once                                              
            root.Update({});
            root.DumpHierarchy();

            REQUIRE(unit.GetCount() == 1);
            REQUIRE(unit.CastsTo<A::User>(1));
            REQUIRE(unit.IsSparse());

            REQUIRE(root.GetUnits().GetCount() == 1);
         }

         // Check for memory leaks after each cycle                     
         REQUIRE(memoryState.Assert());
      }
   }
}