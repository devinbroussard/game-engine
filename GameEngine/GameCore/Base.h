#pragma once

namespace GameCore
{
	class Base
	{
	public:
		/// <summary>
		/// Called when this entity is added to a scene.
		/// </summary>
		void added();

		/// <summary>
		/// Called when this entity is removed from a scene.
		/// </summary>
		void removed();

		/// <summary>
		/// Called before the first update for this scene. It is not necessary to call this function.
		/// </summary>
		void start();

		/// <summary>
		/// Called each time the scene updates.
		/// </summary>
		/// <param name="deltaTime">The time between frames.</param>
		void update(float deltaTime);

		void fixedUpdate(float fixedTimestep);

		/// <summary>
		/// Called when the scene is drawn to the screen.
		/// </summary>
		void draw();
		void end();

		/// <summary>
		/// Called inside added method.
		/// </summary>
		virtual void onAdded() {};

		/// <summary>
		/// Called inside removed method.
		/// </summary>
		virtual void onRemoved() {};
		/// <summary>
		/// Called before the first update for this scene. Override this function.
		/// </summary>
		virtual void onStart() {};

		/// <summary>
		/// Called on each update for this scene. Override this function.
		/// </summary>
		/// <param name="deltaTime"></param>
		virtual void onUpdate(float deltaTime) {};

		/// <summary>
		/// Called inside the fixedUpdate method.
		/// </summary>
		/// <param name="fixedTimestep"></param>
		virtual void onFixedUpdate(float fixedTimestep) {};

		/// <summary>
		/// Whether or not this object. should call its start method.
		/// </summary>
		/// <returns></returns>
		bool getShouldCallStart() { return m_shouldCallStart; }

		/// <summary>
		/// Called when the scene is drawn to the screen. Override this function.
		/// </summary>
		virtual void onDraw() {};
		/// <summary>
		/// Called whenever the end method is called.
		/// </summary>
		virtual void onEnd() {};

	private:

		bool m_shouldCallStart = true;
	};
}
