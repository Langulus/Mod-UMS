///                                                                           
/// Langulus::Module::UMS                                                     
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "User.hpp"
#include "UMS.hpp"


/// User construction                                                         
///   @param producer - the module instance that produced the unit            
///   @param descriptor - instructions for configuring the unit               
User::User(UMS* producer, const Many& descriptor)
   : Resolvable   {this}
   , ProducedFrom {producer, descriptor} {
   VERBOSE("Initializing...");
   Couple(descriptor);
   VERBOSE("Initialized");
}

/// Update routine                                                            
///   @param deltaTime - time between updates                                 
///   @return false                                                           
bool User::Update(Time) {
   return false;
}

/// React on environmental change                                             
void User::Refresh() {
}
