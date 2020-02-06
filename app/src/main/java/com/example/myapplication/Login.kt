package com.example.myapplication

import android.content.Intent
import android.os.Bundle
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import com.github.kittinunf.fuel.httpGet
import com.github.kittinunf.result.Result
import kotlinx.android.synthetic.main.activity_login.*

class Login : AppCompatActivity() {
    val URL = "https://nast-blog.herokuapp.com/login"

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_login)
        var i :Intent = getIntent()
        var password = i.getStringExtra("password")
        var username = i.getStringExtra("username")
        var req : String = URL + username + "/" + password
        var person = req.httpGet().responseObject(User.Deserializer()).third.component1()
        about_me.text = person?.about_me
    }

    fun MakePost(view: View){

    }
}
