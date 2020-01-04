package com.example.myapplication

import android.content.Intent
import android.os.Bundle
import android.view.View
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    fun Login(view: View){
        val loginIntent = Intent(this, Login::class.java)
        startActivity(loginIntent)
    }

    fun Registration(view: View){
        val loginIntent = Intent(this, Registration::class.java)
        startActivity(loginIntent)
    }

}
