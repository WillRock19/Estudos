﻿using BCC.Canteen.Model;
using FluentValidation;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BCC.Canteen.Validation
{
    public class SaleItemValidator : AbstractValidator<SaleItem>
    {
        public SaleItemValidator() : base()
        {
            
        }
    }
}
