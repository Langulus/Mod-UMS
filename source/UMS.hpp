///                                                                           
/// Langulus::Module::UMS                                                     
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "User.hpp"
#include <Langulus/Flow/Factory.hpp>
#include <Langulus/Verbs/Create.hpp>


///                                                                           
///   User management system module                                           
///                                                                           
struct UMS final : A::UserModule {
   LANGULUS(ABSTRACT) false;
   LANGULUS_BASES(A::UserModule);
   LANGULUS_VERBS(Verbs::Create);

private:
   TFactory<User> mUsers;

public:
   UMS(Runtime*, const Many&);

   bool Update(Time);
   void Create(Verb&);
   void Teardown();
};