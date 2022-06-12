/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:46:43 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:46:43 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M06_DATATRANSFEROBJECT_H
#define M06_DATATRANSFEROBJECT_H

#include <string>
#include <stdint.h>


typedef struct s_Data {
    int n;
    std::string str;
} Data;

uintptr_t serialize(Data *ptr);

Data *deserialize(uintptr_t raw);

#endif //M06_DATATRANSFEROBJECT_H
