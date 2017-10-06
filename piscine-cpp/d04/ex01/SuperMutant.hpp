/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:20:07 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 14:26:08 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy {
public:
  SuperMutant(void);
  SuperMutant(SuperMutant const & src);
  virtual ~SuperMutant(void);

  SuperMutant& operator=(SuperMutant const & rhs);

  virtual void takeDamage(int damages);
};

#endif