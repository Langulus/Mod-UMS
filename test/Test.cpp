///                                                                           
/// Langulus::Module::UMS                                                     
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include <Langulus/CppAPI/User.hpp>                          
#include <Langulus/Testing.hpp>                          


SCENARIO("Main testing scenario for UMS", "[UMS]") {
   static Allocator::State memoryState;
   
   for (int repeat = 0; repeat != 10; ++repeat) {
      GIVEN(std::string("Init and shutdown cycle #") + std::to_string(repeat)) {
         // Create root entity                                          
         auto root = Thing::Root<false>("UMS");

         WHEN("Components created via abstractions (not mandatory)") {
            auto part = root.CreateUnit<Things::User>();

            // Update once                                              
            root.Update({});
            root.DumpHierarchy();

            REQUIRE(part.GetCount() == 1);
            REQUIRE(part.CastsTo<Things::User>(1));
            REQUIRE(part.IsSparse());

            REQUIRE(root.GetUnits().GetCount() == 1);
         }

         WHEN("Components created via tokens (mandatory)") {
            auto part = root.CreatePartToken("Things::User");

            // Update once                                              
            root.Update({});
            root.DumpHierarchy();

            REQUIRE(part.GetCount() == 1);
            REQUIRE(part.CastsTo<Things::User>(1));
            REQUIRE(part.IsSparse());

            REQUIRE(root.GetUnits().GetCount() == 1);
         }

         // Check for memory leaks after each cycle                     
         REQUIRE(memoryState.Assert());
      }
   }
}