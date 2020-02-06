package com.example.myapplication

import com.github.kittinunf.fuel.core.ResponseDeserializable
import com.google.gson.Gson
import kotlinx.serialization.Serializable

@Serializable
class User {
    var username: String = ""
    var post_count: Int = 0
    var last_seen: String = ""
    var id: Int = 0
    var follower_count: Int = 0
    var followed_count: Int = 0
    var about_me: String = ""

    class _links {
        var avatar: String = ""
        var followed: String = ""
        var followers: String = ""
        var self: String = ""
    }

    class Deserializer : ResponseDeserializable<User> {
        override fun deserialize(content: String): User? =
            Gson().fromJson(content, User::class.java)
    }
}