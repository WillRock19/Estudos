﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using EntityTeste.Models;

namespace EntityTeste
{
    public partial class Digitar1 : formDigitar
    {
        // apenas para demsntrar como é carregado automaticamente a dao do pedido pelo inbjector
        private IBaseDAO<Pedido> _pedido;

        public Digitar1(IBaseDAO<Pedido> pedido)
        {
            InitializeComponent();


            // aqui define que model utilizar no digitar
            // o register fala que campo pertence a que propriedade
            setModel<Cliente>()
                .Register(e=>e.Name, txtNome)
                .Register(e=>e.Telefone, txtFone);
                                   

            //injeta pedido para usar em qualquer coisa
            _pedido = pedido;

           
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var ee = getModelEE<Cliente>();


            // poe um brakpoint aqui e ve os dados do model!
            MessageBox.Show(String.Format("Nome:{0} Telefone:{1}", ee.Name, ee.Telefone));

        }

       

         
    }
}
