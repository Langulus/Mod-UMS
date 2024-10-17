///                                                                           
/// Langulus::Module::UMS                                                     
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "UMS.hpp"


/// This macro exposes your types to flows and sets some global module        
/// properties. It needs to be called once in a single CPP file.              
LANGULUS_DEFINE_MODULE(
   UMS, 0, "UMS",
   "User management system", "",
   UMS, User
)

/// Module construction                                                       
///   @param runtime - the runtime that owns the module                       
///   @param descriptor - instructions for configuring the module             
UMS::UMS(Runtime* runtime, const Many& descriptor)
   : Resolvable {this}
   , A::Module  {runtime} {
   VERBOSE("Initializing...");
   VERBOSE("Initialized");
}

/// First stage destruction                                                   
void UMS::Teardown() {
   mUsers.Teardown();
}

/// Module update routine                                                     
///   @param deltaTime - time between updates                                 
///   @return false                                                           
bool UMS::Update(Time deltaTime) {
   for (auto& user : mUsers)
      user.Update(deltaTime);
   return false;
}

/// Create/destroy units in this module instance                              
///   @param verb - the creation/destruction verb                             
void UMS::Create(Verb& verb) {
   mUsers.Create(this, verb);
}