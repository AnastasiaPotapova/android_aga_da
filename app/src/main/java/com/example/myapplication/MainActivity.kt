package com.example.myapplication

import android.content.Intent
import android.os.Bundle
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import com.example.myapplication.Login
import com.example.myapplication.Registration
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {
    var username = ""
    var password = ""

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    fun Login(view: View){
        val loginIntent = Intent(this, Login::class.java)

        username = Username.text.toString()
        password = Password.text.toString()

        loginIntent.putExtra("username", username)
        loginIntent.putExtra("password", password)

        startActivity(loginIntent)
    }

    fun Registration(view: View){
        val loginIntent = Intent(this, Registration::class.java)
        startActivity(loginIntent)
    }

}
